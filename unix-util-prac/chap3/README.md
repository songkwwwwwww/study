chap3 정리
=

## preprocess
**cpp0 or cc -E 이 담당.**


## compile
**cc가 담당.**

*.c 파일이 있을 때
(예를 들어 like.c)

gcc로 컴파일할 때 -g 옵션을 추가하면(디버깅 옵션)
gcc -g -o like like.c

like 실행 파일에 대해 objdump 명령으로 실행 파일의 내용을 알 수 있다.
objdump -S like
(-S 옵션을 주면 like 파일의 디버깅 정보와 함께 instruction과 instruction에 대응하는 assembly code를 확인할 수 있다.)


gcc -v -save-temps -o like like.c
-v : 컴파일되는 과정을 화면으로 출력
-save-temps : 컴파일 과정에서 발생되는 중간 파일을 지우지 않고 저장

-I[include directory] : include 디렉토리 추가
    ex) gcc -I/root/include -o like like.c



## assemble
**as가 담당**

as에 의해 생성되는 like.o 파일은 어셈블된 like.s 의 instruction과 data가 들어있는 ELF binary format을 가진다.
(binary format이란 binary file의 구조를 결정짓는 규약)
[ELF : Excutable and Linking Format](https://en.wikipedia.org/wiki/Executable_and_Linkable_Format)

loader는 실행 파일을 어떤 식으로 메모리에 올려야하는가?
    -> 때문에 바이너리 파일의 구조를 알아야 한다.

ELF format binary를 보는 방법
readelf -a like.o

ELF Header 외에도 Program Header 가 포함될 수 있는데,
like.o 처럼 재배치 가능한 object 가 아닌 실행 바이너리 같은 것들에 포함된다.

Program Header Table은 커널 로더에 필요한 정보들을 제공하는 테이블로, 프로그램을 섹션 단위가 아닌 세그먼트 단위로 보여준다.

gcc는 내부적으로 printf()를 puts()로 변경한다. 이 외에도 여러 가지가 있으며,  이를 빌트인 확장이라고 한다.
gcc의 여러 향상된 확장 기능을 제공하기 위해 사용되며 __builtinin_[함수명]() 형식의 이름을 가진다.
빌트인 확장이 일어나는 시점과 해당하는 함수의 종류는 gcc 버전에 따라 다르다.
gcc-4.1.x는 GIMPLE 트리를 만드는 시점에 발생하고 gcc-4.0.x는 RTL을 만드는 시점에 발생.
컴파일  시 -fdump-tree-all -da 옵션을 추가하면 위 과정을 확인할 수 있다.
(gimple 혹은 expand 파일)
컴파일 시 -fno-builtin 옵션을 추가하면 이러한 확장이 일어나지 않는다.

심볼 테이블은 nm 명령을 통해 읽을 수 있다.

binary format의 전체 내용 보기
xxd like.o


## linking
**collect2가 담당**

최신 컴파일러에서 collect2는 내부적으로 진짜 링커인 ld를 호출한다.


표준 C 라이브러리는 /usr/lib 디렉토리에 libc.a 라는 이름으로 존재한다.
정적 라이브러리는 "lib[라이브러리 이름].a" 의 형식이다.(확장자가 .a)




*static library*


*share library*

binary의 PLT 섹션의 내용과 GOT 섹션의 내용은 
objdump -D like 명령 혹은 objdump -j .plt -D like와 objdump -j .got -s like 명령으로 확인 가능하다.

최종적으로 생성되는 like 바이너리 구조는 -WI,-M 옵션을 추가해 컴파일하면 확인할 수 있다.
gcc -o like like.c -save-temps -Wl,-M >& like.lds


자신의 시스템에서 사용하는 표준 C 공유 라이브러리와 동적 링커는 컴파일된 like 바이너리에서 ldd like 명령을 사용해 확인할 수 있다.


