package solve
import kotlin.math.*

fun main(args: Array<String>) {
    val t = readLine()!!.toInt()

    for(i in 0..t-1) {
        var input = readLine()!!.split(' ')
        var x1 = input[0].toDouble()
        var y1 = input[1].toDouble()
        var r1 = input[2].toDouble()
        var x2 = input[3].toDouble()
        var y2 = input[4].toDouble()
        var r2 = input[5].toDouble()

        var dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))

        if (x1 == x2 && y1 == y2 && r1 == r2)
            println(-1)
        else if(dist == r1+r2 || dist == abs(r1-r2))
            println(1)
        else if(dist > r1+r2 || dist < abs(r1-r2))
            println(0)
        else
            println(2)
    }
}