# Compiler
我写的lex.l放在了/project里，其他东西是老师仓库照搬过来的


# 需要实现的error

Lexical error (error type A):
    there are undefined characters or tokens in the SPL program:
        int a = @;
    
    identifiers starting with digits:
        int 1stPerson = 1;

Syntax error (error type B):
    missing closing symbol:
        fibonacci(10;
        
        fibonacci(int n){
            ...
    
    missing semicolon:
        int a = 1