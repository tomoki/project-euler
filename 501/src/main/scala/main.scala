import scala.io.StdIn.readLine
import scala.collection.mutable.PriorityQueue
import scala.collection.immutable.VectorBuilder
import scala.annotation.tailrec
import scala.util.control.Breaks

package Lib {
  package Number {
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
    final def prime_decomposition(n : Int, primes : Array[Int]) : Vector[Int] = {
      val v = new VectorBuilder[Int]()
      val b = new Breaks
      var c = n
      for(p <- primes){
        if(c == 1)
          b.break
        while(c % p == 0){
          c = c / p
          v += p
        }
      }
      v.result
    }
  }
}


object Main {
  // 1,2,3 -> 1 | 4,5,6,7,8 -> 2 | 9... -> 3
  def sqrt_ceil(n : Long) : Long = {
    val EPS = 1e-8
    Math.sqrt(n.toDouble+EPS).toLong
  }
  def count_divisors(n : Long) : Int = {
    val u = sqrt_ceil(n)
    val l = if(u*u == n) -1 else 0
    val k = 2*(1l to u).count(n % _ == 0l)
    k + l
  }
  def solve(n : Long) : Long = {
    // (1l to n).par.count(count_divisors(_) == 8)
    var i = 1l
    var k = 0
    while(i <= n){
      if(count_divisors(i) == 8){
        println(i)
        k += 1
      }
      i += 1
    }
    k
  }
  def main(args : Array[String]) : Unit = {
    val n = readLine().toLong
    println(solve(n))
  }
}
