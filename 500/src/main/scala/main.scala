import scala.io.StdIn.readLine
import scala.collection.mutable.PriorityQueue
import scala.annotation.tailrec

object Lib {
  object Number {
    final def sieve(n : Int) : Array[Boolean] = {
      val isprime = Array.fill(n+1)(true)
      isprime(0) = false
      isprime(1) = false
      for(i <- 2 to Math.ceil(Math.sqrt(n.toDouble)).toInt;
          if isprime(i);
          j <- i*i until n by i){
        isprime(j) = false
      }
      isprime
    }
    final def primes(n : Int) : Array[Int] =
      sieve(n).zipWithIndex.withFilter(_._1).map(_._2)
  }
}


object Main {
  def main(args : Array[String]) : Unit = {
    val nk = 500500
    val mod = 500500507
    val primes = Lib.Number.primes(10000000)
    val pq = PriorityQueue[Long]()(scala.math.Ordering.Long.reverse)
    primes.foreach(pq += _)
    @tailrec
    def rec(n : Int, cur : Long,pq : PriorityQueue[Long]) : Long = {
      if(n == nk) cur
      else {
        val h = pq.head
        // println(n + " " + cur + " " + h)
        pq.dequeue
        pq.enqueue(h*h)
        rec(n+1,((cur*h)%mod),pq)
      }
    }
    println(rec(0,1,pq))
  }
}
