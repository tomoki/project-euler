import scala.io.StdIn.readLine
import scala.collection.mutable.PriorityQueue
import scala.annotation.tailrec

package Lib {
  object Number {
    // @return Array length is equal to 'n'.
    //  Kth element of Array is true if K is prime else false.
    final def sieve(n : Int) : Array[Boolean] = {
      val isprime = Array.fill(n+1)(true)
      isprime(0) = false
      isprime(1) = false
      for(i <- 2 to Math.ceil(Math.sqrt(n.toDouble)).toInt;
          if isprime(i);
          j <- i*i to n by i){
        isprime(j) = false
      }
      isprime
    }
    // @return Array of primes that is less than or equal to n
    final def primes(n : Int) : Array[Int] =
      sieve(n).zipWithIndex.withFilter(_._1).map(_._2)
    final def doubling[T](x : T, n : Long, zero : T, bop : (T,T) => T) : T =
      if(n == 0) zero
      else if(n % 2 == 0) doubling(bop(x,x),n/2,zero,bop)
      else bop(doubling(bop(x,x),n/2,zero,bop),x)
    final def sqrt_ceil(n : Long) : Long = {
      val EPS = 1e-8
      Math.sqrt(n.toDouble+EPS).toLong
    }
  }
}

object Main {
  // def solve(d : Long) : Option[Long] = {
  //   val INF = 100000000L
  //   def have_answer(x : Long) : Boolean = {
  //     if((x*x-1) % d != 0){
  //       false
  //     }else {
  //       val y = Math.ceil.sqrt_ceil((x*x-1)/d)
  //       y*y == (x*x-1)/d
  //     }
  //   }
  //   if(sqrt_ceil(d)*sqrt_ceil(d) == d)
  //     None
  //   else
  //     (2L to INF).find(have_answer(_)) match {
  //       case None    => println(s"$d not found");None
  //       case Some(k) => Some(k)
  //     }
  // }
  // def doit(n : Long) : Long = {
  //   val ans = (2L to n).par.map((i) => (i,solve(i))).toVector.
  //               sortBy({
  //                        case (_,None   ) => 10000000
  //                        case (_,Some(k)) => -k
  //                      }).head._1
  //   ans
  // }
  val doubles = {
  }
  def solve(_d : Long) : Option[BigInt] = {
    val INF = 100000L
    val d = BigInt(_d)
    def have_answer(x : BigInt) : Boolean = {
      false
    }
    (1L to INF).find((k) => have_answer(k*d+1))  match {
      case None    => println(s"$d not found");None
      case Some(k) => Some(k)
    }
  }
  def doit(n : Long) : Long = {
    val ans = Lib.Number.primes(n.toInt).par.map((i) => (i,solve(i))).toVector.
      sortBy({
               case (_,None   ) => BigInt(100)
               case (_,Some(k)) => -k
             }).head._1
    ans
  }
  def main(args : Array[String]) : Unit = {
    val n = 1000
    println(doit(n))
  }
}
