#include <iostream>
using namespace std ;

void merge( int* a , int l , int m , int r ) {
    int i = l , j = m+1 , b[r-l+1] , idx = 0 ;
    // ให้กลุ่มซ้ายคือ a[l] ถึง a[m] และกลุ่มขวาคือ a[m+1] ถึง a[r]
    // กำหนด i ให้เป็น index ของสมาชิกจากกลุ่มซ้ายที่เรากำลังพิจารณา ซึ่งเริ่มต้นจากตัวแรกของกลุ่มซ้าย ( l )
    // กำหนด j ให้เป็น index ของสมาชิกจากกลุ่มขวาที่เรากำลังพิจารณา ซึ่งเริ่มต้นจากตัวแรกของกลุ่มขวา ( m+1 )
    // กำหนด array b ขนาด r-l+1 ให้เป็น array รองรับในการนำสมาชิกจากกลุ่มซ้ายและขวามาเรียง ( ตั้งแต่ a[l] ถึง a[r] สมาชิกทั้งหมด r-l+1 ตัว )
    // กำหนด idx ให้เป็น index ใน b โดยตำแหน่งของ b[idx] จะพร้อมรับค่าจากกลุ่มซ้ายหรือขวา ซึ่งเริ่มต้นจาก 0
    // ไล่ดูสมาชิกของกลุ่มซ้ายและกลุ่มขวา แล้วนำมาวางเรียงลำดับกัน *การเรียง ใช้เวลาแค่ O(N) เพราะกลุ่มซ้ายและขวาถูกเรียงมาแล้ว*
    while( i <= m && j <= r ){  // while loop นี้หยุดเมื่อไล่ดูสมาชิกกลุ่มใดกลุ่มหนึ่งจนหมดแล้ว
        if( a[i] < a[j] ) {     // เทียบ a[i] กับ a[j] แล้วเอาตัวน้อยกว่าเข้าไปวางใน b ก่อน
            b[idx] = a[i] ;
            ++i ;               // ถ้าตัวไหนถูกเอาออกไปวางใน b แล้ว ก็จะไปพิจารณาตัวต่อไปในกลุ่มเดียวกันกับตัวนั้น
        } else {
            b[idx] = a[j] ;
            ++j ;
        }
        ++idx ;                 // b[idx] รับค่าไปแล้ว จึงเลื่อน idx ไปยังตำแหน่งต่อไปเพื่อรอรับค่าใหม่
    }
    // 2 ลูปข้างล่างนี้ จะได้วนแค่ตัวใดตัวหนึ่งเท่านั้น เพราะจะมาถึงบรรทัดนี้ได้ ต้องมีกลุ่มใดกลุ่มหนึ่งถูกไล่ดูสมาชิกจนหมดไปแล้ว ดังนั้นจะเหลือเพียงกลุ่มเดียวที่มีสมาชิกเหลือ
    while( i <= m ) b[idx] = a[i] , ++idx , ++i ; // ถ้ากลุ่มซ้ายยังไม่หมด ให้เอาเข้าไปเลย ( เรียงอยู่แล้ว )
    while( j <= r ) b[idx] = a[j] , ++idx , ++j ; // ถ้ากลุ่มขวายังไม่หมด ให้เอาเข้าไปเลย ( เรียงอยู่แล้ว )
    for( int i = l ; i <= r ; ++i ) a[i] = b[i-l] ; // แทนแต่ละตัวใน b เข้าไปใน a[l] ถึง a[r]
    // a[l] ถึง a[r] จะถูกเรียง
    return ;
}

void msort( int* a , int l , int r ) {
    int m = (l+r)/2;            // หาตำแหน่งตรงกลาง
    if( l == r ) return ;       // ถ้า l เท่ากับ r คือ เรากำลังพิจารณาแค่ตัวเดียวอยู่ เรารู้ว่ากลุ่มที่มีสมาชิก 1 ตัว ถูกเรียงแล้ว
    msort( a , l , m );         // ไปทำซ้ายให้เรียบร้อย  a[l] ถึง a[m]
    msort( a , m+1 , r );       // ไปทำขวาให้เรียบร้อย  a[m+1] ถึง a[r]
    merge( a , l , m , r );     // รวมทางซ้ายกับขวาเข้าด้วยกัน ได้ a[l] ถึง a[r]
}

void merge_sort( int* a , int n ) {
    msort( a , 0 , n-1 ) ; // เริ่มในขอบเขตตัวที่ 0 ถึง n-1
}

int main(){
    int a[] = { 5 , 8 , 1 , 10 , 9 , 7 , 12 , 2 , 3 , 4 } ;
    int n = sizeof( a ) / sizeof( a[0] ) ;

    cout << "Before merge sort : " ;
    for( int i : a ) cout << i << " " ;
    cout << "\n";
    
    merge_sort( a , n ) ; 
    
    cout << "After merge sort : " ;
    for( int i : a ) cout << i << " " ;
    cout << "\n";
}