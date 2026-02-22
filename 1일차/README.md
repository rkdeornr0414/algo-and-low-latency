# 1일차: C++ 알고리즘 + Low Latency 시작

## 오늘 목표
- C++로 시간 측정을 직접 해본다 (`std::chrono`)
- `vector`의 `reserve()`가 왜 중요한지 수치로 확인한다
- 알고리즘 핵심 패턴 2개를 손으로 구현한다
  - 투포인터
  - 슬라이딩 윈도우

## 진행 순서 (약 2~3시간)
1. 빌드
2. `latency_lab` 실행해서 측정값 확인
3. `algorithm_lab_day1.cpp`의 TODO 구현
4. 테스트 통과
5. 오늘 회고 작성

## 빌드/실행 (현재 환경 기준: g++)
```powershell
New-Item -ItemType Directory -Force -Path build | Out-Null
& "C:\msys64\ucrt64\bin\g++.exe" -std=c++20 -O2 -Wall -Wextra -pedantic src/algorithm_lab_day1.cpp -o build/algorithm_lab.exe
& "C:\msys64\ucrt64\bin\g++.exe" -std=c++20 -O2 -Wall -Wextra -pedantic src/latency_lab_day1.cpp -o build/latency_lab.exe
.\build\algorithm_lab.exe
.\build\latency_lab.exe
```

## 빌드/실행 (선택: CMake가 설치된 경우)
```powershell
cmake -S . -B build
cmake --build build -j
.\build\algorithm_lab.exe
.\build\latency_lab.exe
```

## 실습 파일
- 알고리즘: `src/algorithm_lab_day1.cpp`
- 저지연 측정: `src/latency_lab_day1.cpp`

## 오늘 체크리스트
- [ ] `algorithm_lab` 테스트 모두 통과
- [ ] `latency_lab` 결과를 보고 어떤 코드가 느린지 설명 가능
- [ ] 아래 회고 3줄 작성

## 회고 템플릿
- 오늘 가장 헷갈린 개념:
- 직접 측정해보고 놀란 점:
- 내일 보완할 것:
