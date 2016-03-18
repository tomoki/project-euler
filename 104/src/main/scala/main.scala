import scala.io.StdIn.readLine
import scala.collection.mutable.PriorityQueue
import scala.annotation.tailrec
import scala.util.control.Breaks

object Main {
  def main(args : Array[String]) : Unit = {
    var a = BigInt(1)
    var b = BigInt(1)
    var (la,lb) = (1L,1L)
    var r = 3
    val ok = "123456789"
    def check(a : BigInt) = {
      val s = a.toString
      val h = s.take(9).sorted
      val t = s.takeRight(9).sorted
      h == ok && t == ok
    }
    val d = new Breaks
    d.breakable{
      while(true){
        val c = a + b
        val lc = (la + lb) % 1000000000L
        if(lc.toString.sorted == ok && check(c)){
          println("\nANS:" + r)
          d.break
        }
        print("\rcnt: " + r)
        // Console.flush()
        a = b
        b = c
        la = lb
        lb = lc
        r += 1
      }
    }
  }
}
