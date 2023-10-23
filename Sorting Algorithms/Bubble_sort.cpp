#include <iostream>
using namespace std ;

void Bubble_sort ( int* a , int n ) {
    // concept ง่าย ๆ
    // ไล่ดูทีละตัว ถ้ามากกว่าทางขวาของมัน >> สลับตัวนั้นกับทางขวา เมื่อสลับไปเรื่อยๆจนครบ array แล้ว ตัวที่มากที่สุด ก็จะไปอยู่ทางขวาสุด ( อยู๋ถูกที่แล้ว )
    // ทำแบบเดิมแต่ไม่ต้องไปยุ่งกับตัวที่ถูกตำแหน่งแล้ว
    for( int i = 0 ; i < n-1 ; ++i ) { 
        for( int j = 0 ; j < n-1-i ; ++j ) {    // วนถึง n-1-i เพราะตัวที่ n-i+1 ถึงตัวที่ n-1 อยู่ถูกตำแหน่งแล้ว ( เรียงแล้ว ) *คำอธิบายบายอยู่บรรทัด 10-16
            if( a[j] > a[j+1] ) {               // ถ้า a[j] มีค่ามากกว่าตัวทางขวาของมัน
                swap ( a[j] , a[j+1] ) ;        // สลับ a[j] กับตัวทางขวา
            }
            // เมื่อวนลูปจนจบตัวที่มากที่สุดของช่วง 0 ถึง n-i จะไปอยู๋ที่ n-i
            // พิสูจน์
            // ถ้าสมมติว่า a[k] คือตัวที่มากที่สุดในช่วง 0 ถึง n-i
            // เมื่อวนลูปมาจน j เท่ากับ k แล้วเนื่องจาก a[k] มากที่สุด และ j = k ดังนั้น a[j] จะมากกว่าตัวทางขวามัน ( a[j+1] ) และจะสลับค่ากัน
            // ดังนั้นลูปครั้งต่อไปก็จะเลื่อนไปดูตัวที่ j+1 ก็คือตัวที่ถูกตัวที่มากที่สุดแทนที่
            // เมื่อเป็นเช่นนั้นการลูปทุกครั้งก็จะมีการสลับค่าที่มากที่สุดไปทางขวาเรื่อยๆจนถึงตำแหน่งสุดท้ายที่ n-i (ตำแหน่งที่ถูก)
            // ซึ่งช่วง n-i+1 ถึง n-1 ก็จะอยู๋ในตำแหน่งที่ถูกอยู่แล้ว ( เรียงแล้ว ) เพราะถูกคัดมาก่อนหน้านี้แล้ว
        }
    }
    return ;
}

int main() {
    int a[] = { 5 , 8 , 1 , 10 , 9 , 7 , 12 , 2 , 3 , 4 } ;
    int n = sizeof( a ) / sizeof( a[0] ) ;
    
    cout << "Before Bubble sort : " ;
    for ( int i : a ) cout << i << " " ;
    cout << "\n";
    
    Bubble_sort ( a , n ) ; 
    
    cout << "After Bubble sort : " ;
    for ( int i : a ) cout << i << " " ;
    cout << "\n";
}
