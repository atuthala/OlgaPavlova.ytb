Olga Pavlova

## [Как работает и не работает обобщённый указатель void * в C (Си)](https://www.youtube.com/watch?v=uakAypiG7Zo)
```
 32:00 создаём src/main.c
 47:00 откомпилировали и запустили
 1:07:00 добавили указатель на указатель


 1:12:25 void free_regmem(){}
 
 
Ловим утечки памяти:
1) компилируем 
    clang –ggdb –std=c99 –Wall –Werror   main.c –lcrypt –lcs50 –lm –o main
 
    gcc -O0 -g main.c -o main
 
 2) запускаем 
    valgrind ./main
 ```