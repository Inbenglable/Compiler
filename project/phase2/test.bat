for %%I in (1,2,3,4,5) do (
    wsl ./bin/splc ./test/test_12112421_%%I.spl > ./test/test_12112421_%%I.out
    wsl ./bin/splc ./test/test_12112822_%%I.spl > ./test/test_12112822_%%I.out
    wsl ./bin/splc ./test/test_12112620_%%I.spl > ./test/test_12112620_%%I.out
)

for %%I in (1,2,3,4,5,6,7) do (
    wsl ./bin/splc ./test-ex/test_%%I.spl > ./test-ex/test_%%I.out
)