/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
*/

//C++
bool isPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
        while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
        while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if no alphanumeric
        if (toupper(s[i]) != toupper(s[j])) return false; // Exit and return error if not match
    }
    
    return true;
}

bool isPalindrome(string s) {
	int start=0, end=s.length()-1;
	while(start<end) {
		if (!isalnum(s[start])) start++;
		else if (!isalnum(s[end])) end--;
		else {
			if (tolower(s[start++])!=tolower(s[end--])) return false;
		}
	}
	return true;
}

bool isPalindrome(char* s) {
    int len = strlen(s);
    if(!len) return true;
    char *p1 = s, *p2 = s + len - 1;
    while(p1 < p2){
        if(!isalnum(*p1)){p1++;continue;}
        if(!isalnum(*p2)){p2--;continue;}
        if(tolower(*p1++) != tolower(*p2--)) return false;
    }
    return true;
}
