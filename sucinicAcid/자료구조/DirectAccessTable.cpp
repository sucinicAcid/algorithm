/*
# DAT (Direct Address Table)

  1. 값이 곧 인덱스가 됨
  2. 탐색 O(1)
  
  단점: 음수, 매우큰수, 문자열은 인덱스 불가능
  -> 해쉬로 인덱스 생성
     탐색할때도 해쉬로 생성한 인덱스로 탐색
*/

#include <iostream>

int vect[6] = { 5, 1, 7, 3, 2 };
int dat[100];

void init()
{
	for (int i = 0; i < 6; i++) {
		int idx = vect[i]; // DAT는 값이 곧 인덱스
		dat[idx] = 1;
	}
}

int main(void)
{
	init();

	return 0;
}