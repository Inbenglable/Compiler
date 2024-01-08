import os


TEST_PATH = './test'


if __name__ == '__main__':
    os.system('wsl make')
    files = os.listdir(TEST_PATH)
    for file in files:
        if file.endswith('.spl'):
            print('Compiling ' + file)
            os.system('wsl ./bin/splc ' + os.path.join(TEST_PATH, file))