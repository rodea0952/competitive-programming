fun main(args: Array<String>) {
    val(n, k) = readLine()!!.split(" ").map(String::toInt)
    val s = readLine()!!

    var same = 0
    for(i in 0..n-2){
        if(s[i] == s[i+1]) same++
    }

    println(Math.min(n - 1, same + 2 * k))
}
