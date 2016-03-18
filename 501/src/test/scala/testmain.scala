import org.scalatest.FlatSpec
import java.nio.file.{Paths, Files}

class MainSpec extends FlatSpec {
  def execWithDummyStdio(main : (Array[String]) => Unit, input : String) : String = {
    val istream = new java.io.ByteArrayInputStream(input.getBytes)
    val ostream = new java.io.ByteArrayOutputStream
    Console.withIn(istream) { Console.withOut(ostream) {
        main(Array[String]())
    } }
    return ostream.toString
  }
  def lsFile(dir : String) : Seq[java.io.File] = {
    new java.io.File(dir).listFiles.filter(_.isFile)
  }
  def getExtension(name : String) : String = {
    val n = name.lastIndexOf(".")
    if(n == -1) ""
    else name.substring(n+1)
  }
  def eraseExtension(name : String) : String = {
    val n = name.lastIndexOf(".")
    name.substring(0,n)
  }

  val test_files_dir_str = "./src/test/resources"
  if(!Files.exists(Paths.get(test_files_dir_str))){
    fail("tests directory not found")
  }
  val input_files = lsFile(test_files_dir_str).filter((k) => getExtension(k.getName) == "in")
  for(i <- input_files){
    val o = eraseExtension(i.getPath) + ".out"
    val exist_expected_file = Files.exists(Paths.get(o))
    i.getPath() should o in {
      assert(exist_expected_file)
      val dummy_in = new String(Files.readAllBytes(Paths.get(i.getPath)))
      val start = System.currentTimeMillis();
      val dummy_out = execWithDummyStdio(Main.main,dummy_in)
      val end = System.currentTimeMillis();
      val expected = new String(Files.readAllBytes(Paths.get(o)))
      val interval = end - start;
      println(i.getPath + " -> " + interval + "millis");
      assert(expected == dummy_out)
    }
  }
  "sqrt_ceil(9)" should "3" in {
    assert(Main.sqrt_ceil(9) == 3)
  }
  "sqrt_ceil(12)" should "3" in {
    assert(Main.sqrt_ceil(12) == 3)
  }
  // "count_divisors(24)" should "8" in {
  //   assert(Main.count_divisors(24) == 8)
  // }
  // "count_divisors(4)" should "3" in {
  //   assert(Main.count_divisors(4) == 3)
  // }
  // "count_divisors(16)" should "5" in {
  //   assert(Main.count_divisors(16) == 5)
  // }
  // println(Main.count_divisors(100000000000l));
  // "count_divisors(100000000000)" should "5" in {
  //   assert(Main.count_divisors(16) == 5)
  // }
  "solve(100)" should "10" in {
    assert(Main.solve(100) == 10)
  }
  "solve(1000)" should "180" in {
    assert(Main.solve(1000) == 180)
  }
  // println(Lib.Number.primes(25))

  "prime_decompsition(24,primes)" should "[2,2,2,3]" in {
    assert(Lib.Number.prime_decomposition(24,Lib.Number.primes(25)) == Vector(2,2,2,3))
  }

  // "solve(1000000)" should "224427" in {
  //   assert(Main.solve(1000000) == 224427)
  // }
  // println(Main.solve(10000000l))
}
