var sstack = arrayOfNulls<Int>(10000)
var top = -1

fun push(i: Int){
    sstack[++top] = i
}
fun pop() {
    if (top == -1)
        println(-1)
    else {
        println(sstack[top--])

    }
}
fun size(){
    println(top+1)
}
fun empty(){
    if(top == -1)
        println(1)
    else
        println(0)
}
fun top(){
    if(top == -1)
        println(-1)
    else
        println(sstack[top])
}

fun main() {
    var temp: String
    var n = readLine()!!.toInt()

    for(i in 1..n) {
        var input = readLine()!!.split(' ')
        when (input[0]){
            "push" -> push(input[1].toInt())
            "pop" -> pop()
            "size" -> size()
            "empty" -> empty()
            "top" -> top()
        }
    }
}