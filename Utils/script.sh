usage() {
    echo "You can use the following flags:"
    echo "--gtest to install g-test"
    echo "--build to build the executable"
    echo "--run to run the executable"
    echo "--test to build and run the tests"
}

# if no arguments are provided, return usage function
if [ $# -eq 0 ]; then
    usage # run usage function
    exit 1
fi



gtest() {
    git clone https://github.com/google/googletest
    cd googletest
    mkdir build
    cd build
    cmake ..
    make
    make install
}

run () {
    ../Game
}

run_test() {
    g++ -std=c++14 ../Test/main.cpp ../RockPaperScissor/Source/Utilities.cpp ../RockPaperScissor/Source/Scoreboard.cpp -o ../GameTests /usr/local/lib/libgtest_main.a -lgtest_main -lgtest -lpthread
    ../GameTests
}

build() {
    g++ -std=c++14 ../RockPaperScissor/main.cpp ../RockPaperScissor/source/Utilities.cpp ../RockPaperScissor/Source/PrintUtils.cpp ../RockPaperScissor/Source/Computer.cpp ../RockPaperScissor/Source/User.cpp ../RockPaperScissor/Source/Scoreboard.cpp ../RockPaperScissor/Source/LoggingUtil.cpp ../RockPaperScissor/Source/Game.cpp -o ../Game
}

while [ "$1" != "" ]; do
    case $1 in
    --build)
    echo "Building..."
        build
        ;;
    --run)
    echo "Runnimg the game..."
        run
        ;;
    --test)
        echo "Running Tests..."
        run_test
        ;;
    --gtest)
        echo "Installing Gtest..."
        gtest
        ;;    
    -h | --help)
        usage # run usage function
        ;;
    *)
        usage
        exit 1
        ;;
    esac
    shift # remove the current value for `$1` and use the next
done