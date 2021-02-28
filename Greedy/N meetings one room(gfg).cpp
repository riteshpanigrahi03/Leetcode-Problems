struct meeting {
    int start;
    int end;
}; // to store the start and end time

bool comparator(struct meeting m1, meeting m2) //comparator function to sort according to end time
{ 
    if (m1.end < m2.end) return true; 
    else if(m1.end > m2.end) return false; 
    return false; 
} 
int maxMeetings(int s[], int e[], int n) {
    // Your code here
    struct meeting meet[n]; // array of structure
    for(int i = 0;i<n;i++) {
        meet[i].start = s[i], 
        meet[i].end = e[i];
    }
    sort(meet,meet+n,comparator); // sorting according to end time
    int count=0;
    
    int lastMeet = meet[0].end; 
    count++;
    
    for(int i = 1;i<n;i++) {
        if(meet[i].start > lastMeet) {  // if lastMeet end time is less thn next meets start then meet is possible
            lastMeet = meet[i].end; 
            count++;
        }
    }
    return count;
}

/*
S[] = {1,3,0,5,8,5}
F[] = {2,4,6,7,9,9}

After sorting according to end time.
[{1,2},{3,4},{0,6},{5,7},{8,9},{5,9}]

count =1 , lastMeet = 2
Start iteration from index 1
meet[1].start = 3 > lastMeet => meeting possible => count =2 => lastMeet = 4

meet[2].start = 0 > lastMeet => false

meet[3].start = 5 > lastMeet => meeting possible => count =3 => lastMeet = 7

meet[4].start = 8 > lastMeet => meeting possible => count =4 => lastMeet = 9

meet[5].start = 5 > lastMeet => false

return 4
*/



