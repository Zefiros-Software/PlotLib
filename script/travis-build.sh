set -e

premake5 install-package --allow-install --allow-module
premake5 gmake
cd plot
make config=debug_x86
make config=debug_x86_64
make config=release_x86
make config=release_x86_64
#make config=coverage_x86
#make config=coverage_x86_64

cd ../test/

premake5 gmake

cd zpm/
make
cd ../

cd ../docs/images/
../../bin/x86/plot-test
../../bin/x86/plot-testd
#../../bin/x86/plot-testcd

../../bin/x86_64/plot-test
../../bin/x86_64/plot-testd
#../../bin/x86_64/plot-testcd

../../test/zpm/bin/x86/plot-zpm-test