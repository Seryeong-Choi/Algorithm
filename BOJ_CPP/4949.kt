import java.util.ArrayDeque

fun main() {
    var stack = ArrayDeque<Char>()
    var temp: String
    var flag: Boolean = true
    while (true) {
        stack.clear()
        flag = true
        temp = readLine().toString()
        if (temp.length == 1 && temp[0] == '.')
            break
        for (c in temp) {
            //print("$c ")
            if (c == '(' || c == '[')
                stack.add(c)
            else if (c == ')') {
                if (!stack.isEmpty() && stack.last == '(')
                    stack.removeLast()
                else {
                    flag = false
                    break
                }
            } else if (c == ']') {
                if (!stack.isEmpty() && stack.last == '[')
                    stack.removeLast()
                else {

                    flag = false
                    break
                }
            }
        }
        if (flag && stack.isEmpty())
            println("yes")
        else
            println("no")
    }
}