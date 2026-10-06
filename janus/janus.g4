grammar janus;

program :  variables? functions
        ;

variables : variableName ( '[' Digit ']' )?
          | variables variables
          ;

functions : function
          | function functions
          ;

function : 'procedure' functionName statements?
         ;

statements   : assignmentExpression
             | ifConstructor
             | loopConstructor
             | functionCall
             | skip
             | statements statements
             ;

assignmentExpression : variableName ( '[' expression ']' )? assignmentOperator expression
                     ;

ifConstructor : ifExpression fiExpression
              | ifExpression elseExpression fiExpression
              ;

ifExpression : 'if' '('? expression ')'? 'then' statements
             ;

elseExpression : 'else' statements
               ;

fiExpression : 'fi' expression
             ;

loopConstructor : fromExp doExp? loopExp? untilExp
                ;

fromExp : 'from' expression
        ;

untilExp : 'until' expression
        ;

doExp : 'do' statements
      ;

loopExp : 'loop' statements
        ;

expression : Digit
           | TextDigit ( '[' expression ']' )?
           | expression operator expression
           | '(' expression ')'
           ;

functionCall : call functionName
             ;

skip : 'skip'
     ;

assignmentOperator: '+=' | '-=' | '<=>' | '^=';

relationalOperator: '='| '!=' | '<' | '>' | '<=' | '>=';

arithmeticOperator : '*' | '+' | '-' | '/' | '%';

bitwiseOperator : '&' | '|' | '^';

logicalOperator : '&&' | '||';

operator: arithmeticOperator
        | bitwiseOperator
        | relationalOperator
        | logicalOperator
        ;

call : 'call'
     | 'uncall'
     ;

variableName : TextDigit;

functionName : TextDigit;

Digit: [0-9]+
     ;

TextDigit : [a-zA-Z_0-9]+
          ;

WS : [ \t\r\n]+ -> skip
   ;

BlockComment
    :   '/*' .*? '*/'
        -> skip
    ;

LineComment
    :   '//' ~[\r\n]*
        -> skip
;