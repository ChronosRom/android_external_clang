// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm -o - %s | FileCheck %s
//
// CHECK: define void @f0
// CHECK: alloca %struct.s0, align 16
// CHECK: define void @f1
// CHECK: alloca %struct.s0, align 16

struct s0 {
  int Start, End;
  unsigned Alignment;
  int TheStores __attribute__((aligned(16)));
};
extern "C" void f0() {
  (void) s0();
}

extern "C" void f1() {
  (struct s0) { 0, 0, 0, 0 };
}
