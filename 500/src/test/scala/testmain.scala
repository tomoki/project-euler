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
  val n = 10
  val isp = Lib.sieve(40)
  "1" should "not prime" in { assert(isp(1) == false) }
  "2" should "prime"     in { assert(isp(2) == true)  }
  "3" should "prime"     in { assert(isp(3) == true)  }
  "4" should "not prime" in { assert(isp(4) == false) }
  "5" should "prime"     in { assert(isp(5) == true)  }
  "6" should "not prime" in { assert(isp(6) == false) }
  "7" should "prime"     in { assert(isp(7) == true)  }
  "8" should "not prime" in { assert(isp(8) == false) }
  "9" should "not prime" in { assert(isp(9) == false) }

  "30" should "ok" in {assert(Main.check(30,isp) == true)}
  "3" should " no" in {assert(Main.check(3,isp) == false)}
  "4" should " no" in {assert(Main.check(4,isp) == false)}
  // Main.main(Array[String]())
}
