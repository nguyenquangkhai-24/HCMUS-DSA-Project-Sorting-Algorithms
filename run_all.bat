@echo off
set ALGOS=selection-sort insertion-sort binary-insertion-sort bubble-sort shaker-sort shell-sort heap-sort merge-sort quick-sort counting-sort radix-sort flash-sort
set SIZES=10000 30000 50000 100000 300000 500000
set ORDERS=-sorted -nsorted -rev -rand

for %%o in (%ORDERS%) do (
    for %%a in (%ALGOS%) do (
        for %%s in (%SIZES%) do (
            echo ======================================================
            echo Chay thuat toan: %%a - Kich thuoc: %%s - Data: %%o
            group3.exe -a %%a %%s %%o -both
        )
    )
)
pause