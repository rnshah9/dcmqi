FROM --platform=linux/amd64 ubuntu:16.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential cmake git python clang-6.0
ENV CC=gcc
ENV CXX=g++

COPY . /repo
WORKDIR /repo/build
RUN cmake .. -DDCMQI_SUPERBUILD=1
RUN make -j8
RUN clang-6.0 /repo/mayhem/fuzz_floatToStr.cpp -fsanitize=fuzzer,address -L /repo/build/dcmqi-build/bin/ -ldcmqi -L /repo/build/DCMTK-build/lib/ -ldcmsr -ldcmimage -ldcmimgle -ldcmdata -loflog -lofstd -ldcmiod  -o /fuzz

FROM ubuntu:16.04 as package
COPY --from=builder /repo/build/DCMTK-build/bin/dcm2xml /
COPY --from=builder /fuzz /fuzz_floatToStr
