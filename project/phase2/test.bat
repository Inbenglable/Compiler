for %%I in (01,02,03,04,05,06,07,08,09,10,11,12,13,14,15) do (
    wsl ./splc ../test/test_2_r%%I.spl > ../test/myout_case%%I.out
)

for %%I in (1,2,3,4,5,6,7) do (
    wsl ./splc ../test-ex/test_%%I.spl > ../test-ex/test_%%I.out
)