for %%I in (1,2,3,4,5,6) do (
    wsl ./bin/splc ./test/test_3_r0%%I.spl
)

for %%I in (1,2,3) do (
    wsl ./bin/splc ./test-ex/test_%%I.spl
)