import os


TEST_PATH = './test'


if __name__ == '__main__':
    files = os.listdir(TEST_PATH)
    for file in files:
        if file.endswith('.spl'):
            print('Compiling ' + file)
            os.system('wsl ./bin/splc ./test/' + file)