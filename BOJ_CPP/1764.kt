fun main() {
    var temp: String

    var input = readLine()!!.split(' ')
    var n = input[0].toInt()
    var m = input[1].toInt()
    var s = mutableSetOf<String>()
    var ans = sortedSetOf<String>()
    for (i in 1..n) {
        temp = readLine().toString()
        s.add(temp)
    }
    for (i in 1..m) {
        temp = readLine().toString()
        if(s.contains(temp))
            ans.add(temp)
    }
    println(ans.size)
    for(str in ans)
        println(str)
}