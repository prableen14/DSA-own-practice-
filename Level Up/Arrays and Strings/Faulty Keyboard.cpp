/*
1. Your friend is typing his name into a faulty keyboard. 
2. Sometimes, when typing a character 'c', the key might get long pressed, and the character will be typed 1 or more times.
3. You examine the typed characters of the keyboard. Return 'True' if it is possible that it was your friends name, with some characters (possibly none) being long pressed.

Constraints
1. 1 <= name.length <= 1000
2. 1 <= typed.length <= 1000
3. name and typed contain only lowercase English letters.

Format
Input
name = "mannu", typed = "mmaannu"
name = "sumeet", typed = "sumeet"
name = "shree", typed = "sshrre"

Output
true
[Explanation: 'm' and 'a' in 'mannu' were long pressed.]
true
[Explanation: It's not necessary to long press any character.]
false
[Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.]

Example
Sample Input

shree
sshhrreee

Sample Output
true
*/
