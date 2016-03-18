import scala.io.StdIn.readLine
object Lib {
  final def sieve(n : Int) : Array[Boolean] = {
    val isprime = Array.fill(n)(true)
    isprime(0) = false
    isprime(1) = false
    for(i <- 2 to Math.ceil(Math.sqrt(n.toDouble)).toInt;
        if isprime(i);
        j <- i*i until n by i){
      isprime(j) = false
    }
    isprime
  }
}
object Main {
  final def check(n : Int,isprime : Array[Boolean]) : Boolean = {
    (1 to Math.ceil(Math.sqrt(n.toDouble)).toInt)
      .forall((i) => n % i != 0 || isprime(i+n/i))
  }
  def main(args : Array[String]) : Unit = {
    val n = 100000000
    val isprime = Lib.sieve(n+2)
    println("ANS: " + (1 to n).par.filter(check(_,isprime)).map(BigInt(_)).sum)
  }
}
