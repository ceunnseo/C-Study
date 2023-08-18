#include <stdio.h>
#include <string.h>

typedef struct {
    char site[21];
    char password[21];
} SiteInfo;

// 간단한 해시 함수를 사용하여 문자열을 정수로 변환
unsigned int hashFunction(const char *str) {
    unsigned int hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    SiteInfo sites[N];
    for (int i = 0; i < N; i++) {
        scanf("%s %s", sites[i].site, sites[i].password);
    }

    // 해시 테이블 생성
    const int tableSize = 2 * N;  // 충분한 크기의 테이블 크기 선택
    SiteInfo hashTable[tableSize];

    // 해시 테이블에 정보 저장
    for (int i = 0; i < N; i++) {
        unsigned int hashValue = hashFunction(sites[i].site) % tableSize;
        while (hashTable[hashValue].site[0] != '\0') {
            hashValue = (hashValue + 1) % tableSize;
        }
        strcpy(hashTable[hashValue].site, sites[i].site);
        strcpy(hashTable[hashValue].password, sites[i].password);
    }

    // 사이트 주소 찾아서 출력
    for (int i = 0; i < M; i++) {
        char siteToFind[21];
        scanf("%s", siteToFind);

        unsigned int hashValue = hashFunction(siteToFind) % tableSize;
        while (strcmp(hashTable[hashValue].site, siteToFind) != 0) {
            hashValue = (hashValue + 1) % tableSize;
        }
        printf("%s\n", hashTable[hashValue].password);
    }

    return 0;
}
