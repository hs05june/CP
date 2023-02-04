#include<bits/stdc++.h>
using namespace std;

int ini_seg[1000][1000] = { 0 };
int fin_seg[1000][1000] = { 0 };
 
// Rectangular matrix.
int rect[4][4] = {
    { 1, 2, 3, 4 },
    { 5, 6, 7, 8 },
    { 1, 7, 5, 9 },
    { 3, 0, 6, 2 },
};
 
// size of x coordinate.
int size = 4;
 
/*
 * A recursive function that constructs
 * Initial Segment Tree for array rect[][] = { }.
 * 'pos' is index of current node in segment
 * tree seg[]. 'strip' is the enumeration
 * for the y-axis.
*/
 
int segment(int low, int high, int pos, int strip)
{
    if (high == low) {
        ini_seg[strip][pos] = rect[strip][low];
    }
    else {
        int mid = (low + high) / 2;
        segment(low, mid, 2 * pos, strip);
        segment(mid + 1, high, 2 * pos + 1, strip);
        ini_seg[strip][pos] = min(ini_seg[strip][2 * pos] , ini_seg[strip][2 * pos + 1]);
    }
}
 
int finalSegment(int low, int high, int pos)
{
    if (high == low) {
 
        for (int i = 1; i < 2 * size; i++)
            fin_seg[pos][i] = ini_seg[low][i];
    }
    else {
        int mid = (low + high) / 2;
        finalSegment(low, mid, 2 * pos);
        finalSegment(mid + 1, high, 2 * pos + 1);
 
        for (int i = 1; i < 2 * size; i++)
            fin_seg[pos][i] = min(fin_seg[2 * pos][i], fin_seg[2 * pos + 1][i]);
    }
}
 
int finalQuery(int pos, int start, int end, int x1, int x2, int node)
{
    if (x2 < start || end < x1) {
        return 0;
    }
 
    if (x1 <= start && end <= x2) {
        return fin_seg[node][pos];
    }
 
    int mid = (start + end) / 2;
    int p1 = finalQuery(2 * pos, start, mid,x1, x2, node);
 
    int p2 = finalQuery(2 * pos + 1, mid + 1,end, x1, x2, node);
 
    return min(p1,p2);
}
 
int query(int pos, int start, int end, int y1, int y2, int x1, int x2)
{
    if (y2 < start || end < y1) {
        return 0;
    }
 
    if (y1 <= start && end <= y2) {
        return (finalQuery(1, 1, 4, x1, x2, pos));
    }
 
    int mid = (start + end) / 2;
    int p1 = query(2 * pos, start, mid, y1, y2, x1, x2);
    int p2 = query(2 * pos + 1, mid + 1, end, y1, y2, x1, x2);
 
    return min(p1,p2);
}
 
int main()
{
    int pos = 1;
    int low = 0;
    int high = 3;
 
    for (int strip = 0; strip < 4; strip++)
        segment(low, high, 1, strip);
 
    finalSegment(low, high, 1);
 
 
    return 0;
}