/*
Given two strings s and t , write a function to determine if t is an anagram of s.
Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

int cmp(const void * a,const void * b)
{
    return *(char *)a - *(char *)b;
}

bool isAnagram(char* s, char* t) {
    qsort(s,strlen(s),sizeof(char),cmp);
    qsort(t,strlen(t),sizeof(char),cmp);
    if(!strcmp(s,t))
        return true;
    else
        return false;
}
