// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <list>
template<typename T>
class TPQueue {
 private:
    std::list <T> Queue;

 public:
    void push(const T& tp) {
        if (Queue.empty()) {
            Queue.push_back(tp);
        } else {
            bool flag = false;
            for (auto step = Queue.begin(); step != Queue.end(); step++) {
                if ((* step).prior < tp.prior) {
                    Queue.insert(step, tp);
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                Queue.push_back(tp);
            }
        }
    }
    T pop() {
        T q = Queue.front();
        Queue.pop_front();
        return q;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
