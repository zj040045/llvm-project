// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -fclangir -emit-cir %s -o %t.cir
// RUN: FileCheck --input-file=%t.cir %s

// Simple scalar return: __retval should be eliminated.
int add(int a, int b) { return a + b; }

// CHECK-LABEL: cir.func{{.*}} @add(
// CHECK-NOT:     ["__retval"]
// CHECK:         cir.return
// CHECK:       }

// Void return: no __retval at all.
void noop(void) {}

// CHECK-LABEL: cir.func{{.*}} @noop(
// CHECK-NOT:     ["__retval"]
// CHECK:         cir.return
// CHECK:       }
