import scala.annotation.tailrec
object Solution1 {
    def convertToBinary(num: Long, digits: Int): String = {
        @tailrec
        def innerBinary(acc: List[Int], target: Long): List[Int] = {
            target match {
                case 0 | 1 => target.toInt :: acc
                case _ => innerBinary((target % 2).toInt :: acc, (target / 2))
            }
        }
        val res = innerBinary(Nil, num)
        val diff_len = "0" * (digits - res.length)

        diff_len ++ res.mkString
    }

    def formatIPStrings(ip: String, n: Int): Unit = {
        val sb = new StringBuilder()

        val left = ip.split("\\.")(0).toLong
        val midleft = ip.split("\\.")(1).toLong
        val midright = ip.split("\\.")(2).toLong
        val right = ip.split("\\.")(3).toLong

        val total: Long = (left << 24) + (midleft << 16) + (midright << 8) + right

        for (i <- 0 until n)
        do
            val new_total = total + i

            val new_right = new_total & (0xffL)
            val new_midright = (new_total & (0xffL << 8)) >> 8
            val new_midleft = (new_total & (0xffL << 16)) >> 16
            val new_left = (new_total & (0xffL << 24)) >> 24

            sb.append("- ")
            sb.append(new_left.toString)
            sb.append(".")
            sb.append(new_midleft.toString)
            sb.append(".")
            sb.append(new_midright.toString)
            sb.append(".")
            sb.append(new_right.toString)
            sb.append(" -> ")
            sb.append(convertToBinary(new_total, 32).zipWithIndex.foldLeft(""){ (acc, tup) => {
                if tup._2 % 8 == 0 then acc + " " + tup._1
                else acc + tup._1
            }})
            sb.append("\n")

        println(sb.toString)
    }

    def ipToCIDR(ip: String, n: Int): List[String] = {

        formatIPStrings(ip, n)

        Nil
    }
}