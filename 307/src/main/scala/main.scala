import scala.io.StdIn.readLine
import scala.collection.mutable.PriorityQueue
import scala.annotation.tailrec

object Main {
  // choose r object from distinct n.
  @tailrec
  def combi[T](n : T, r : T)(implicit num : Integral[T]) : T = {
    import num._
    if(n < r)
      zero
    else if(r > n-r)
      combi(n,n-r)
    else {
      var ans = one
      var i = zero
      while(i < r){
        ans = ans * (n-i)
        ans = ans / (i+one)
        i = i + one
      }
      ans
    }
  }
  // choose r object from n, but it's ok to choose same object
  // https://www.shinko-keirin.co.jp/keirinkan/kosu/mathematics/kirinuki/kirinuki58.html
  def multicombi[T](n : T, r : T)(implicit num : Integral[T]) : T = {
    import num._
    combi(n+r-one,r)
  }
  def solve(k : Int, n : Int) : BigInt = {
    val all  = multicombi(BigInt(n),BigInt(k))
    val safe = (0 to k/2).map((_b) => {
                                val b = BigInt(_b)
                                val a = k - b*2
                                println(s"$a , $b")
                                combi(BigInt(n),a) * combi(BigInt(n)-a,b)
                              }).sum
      (0 to k/2).map((_b) => {
                       val b = BigInt(_b)
                       val a = k - b*2
                       println(s"$a , $b")
                       combi(BigInt(n),a) * combi(BigInt(n)-a,b)
                     }).foreach(println(_))
    val go = BigInt("1000000000")
    println(safe)
    println(all)
    (all-safe) * go / all
  }
  def main(args : Array[String]) : Unit = {
    // println(solve(20000,1000000))
    println(solve(3,7));
  }
}
