# Day 1 수업 가이드

## 1. 오늘 배울 핵심
- 시간복잡도 O(n), O(n log n) 감각
- 투포인터: 정렬된 배열에서 양 끝 포인터를 조절
- 슬라이딩 윈도우: 구간의 시작/끝을 이동하며 중복 관리
- 저지연 기본: "추측"이 아니라 "측정"으로 판단

## 2. 알고리즘 미션
파일: `src/algorithm_lab_day1.cpp`

### 미션 A: `two_sum_sorted`
- 입력은 정렬됨
- `left=0`, `right=n-1`
- `sum == target`이면 반환
- `sum < target`이면 `left++`
- `sum > target`이면 `right--`

### 미션 B: `longest_unique_substring`
- 윈도우 시작 `left`
- 현재 문자 인덱스 `right`
- 문자를 마지막으로 본 위치를 `unordered_map<char, int>`로 관리
- 이미 윈도우에 있는 문자를 만나면 `left`를 당김
- 매 스텝에서 최대 길이 갱신

## 3. 저지연 미션
파일: `src/latency_lab_day1.cpp`

실행 후 아래 2개를 설명해보기:
- 왜 `vector reserve`가 빨라졌는가
- 왜 문자열 최적화 배율이 상대적으로 작게 나왔는가

## 4. 완료 기준
- `algorithm_lab.exe`가 `All tests passed.` 출력
- `latency_lab.exe` 수치를 근거로 3줄 회고 작성

## 회고 템플릿
- 오늘 가장 헷갈린 개념:
1. std::pair<int, int>는 두개의 값을 하나로 묶는 STL 템플릿 클래스 (int 2개를 하나의 객체로 저장하는 구조)
    - 이 함수는 int 두 개를 묶어서 반환한다.
    - return {left, right}

2. const std::vector<int>& nums
    std::vector<int> -> vector 타입
    벡터를 복사하지않고 참조로 받되, 수정은 못한다.

3. static_cast<int>(x)
    c++타입 변환 연산자

4. std::string_view s
    문자열을 소유하지 않고 그냥 바라보기만 하는 얇은 뷰이다.
    즉, "어디서부터 몇글자를 읽어라"라는 정보만 저장함
    문자열 데이터를 소유하지 않는다.

5. std::unordered_map<char, int> last_seen;
    char를 key로하고, int를 value로 저장하는 해시 테이블 자료구조
    빠른 탐색이 목적일 때 사용
    각 문자에 대한 상태를 기억하는 저장소
    

- 직접 측정해보고 놀란 점:
- 내일 보완할 것:
