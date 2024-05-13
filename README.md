# Push_swap
- **두 개의 스택을 사용해서 가능한 적은 수의 작업으로 데이터를 정렬**하는 프로그램을 프로그래밍하는 프로젝트다.
- 시간 복잡도를 고려하여 코드를 작성하는 방법을 깊이 있게 고민해 볼 수 있었다.

## 요구 사항
- 데이터 정렬을 위해 두 개의 스택 A, B와 두 스택을 조작하기 위해 주어지는 명령 집합을 사용할 수 있다.
- 인자로 받은 정수를 스택 A에 오름차순 정렬하는 명령 목록을 표준 출력으로 표시한다.
- 단 최대한 적은 수의 명령을 사용해야 한다!
### 사용할 수 있는 스택 조작 명령
- **sa (swap a)** : A 스택의 맨 위에 있는 요소 2개를 교환
- **sb (swap b)** : B 스택의 맨 위에 있는 요소 2개를 교환
- **ss** : sa와 sb를 동시에 수행
- **pa (push a)** : B 스택 맨 위에 있는 요소를 A의 맨 위로 푸시
- **pb (push b)** : A 스택의 맨 위에 있는 요소를 B의 맨 위로 푸시
- **ra (rorate a)** : A 스택의 모든 요소를 1씩 위로 이동
- **rb (rorate b)** : B 스택의 모든 요소를 1씩 위로 이동
- **rr** : ra와 rb를 동시에 수행
- **rra (reverse rotate a)** : A 스택의 모든 요소를 1씩 아래로 이동
- **rrb(reverse rotate b)** : B 스택의 모든 요소를 1씩 아래로 이동
- **rrr** : rra와 rrb를 동시에 수행

##
정렬을 위해 Quick Sort 알고리즘을 응용하여 활용했다.
자세한 내용은 [여기서](https://velog.io/@ronn/Pushswap-%EB%91%90-%EC%8A%A4%ED%83%9D%EC%9D%84-%EA%B0%80%EC%A7%80%EA%B3%A0-%EB%8D%B0%EC%9D%B4%ED%84%B0%EB%A5%BC-%EC%A0%95%EB%A0%AC%ED%95%98%EC%9E%90) 확인할 수 있다.
