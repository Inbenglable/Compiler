import os


TEST_PATH = './test/'


if __name__ == '__main__':
    result = os.popen('wsl make')
    print(result.read())
    files = os.listdir(TEST_PATH)
    for file in files:
        if file.endswith('.ir'):
            os.remove(os.path.join(TEST_PATH, file))
    for file in files:
        if file.endswith('.spl'):
            print('Compiling ' + file)
            result = os.system('wsl ./bin/splc ' + os.path.join(TEST_PATH, file))
            print(result)
    os.system('wsl make clean')