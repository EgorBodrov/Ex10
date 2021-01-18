// Copyright 2021 Bodrov Egor
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

template<class T>
class MyStack {
 private:
    T* data;
    int size;
    int head;

 public:
    explicit MyStack(int n)
        : size {n}, head {0} {
        data = new T[n];
    }

    MyStack(const MyStack& st)
        : size {st.size}, head {st.head} {
        data = new T[size];
        for (int i = 0; i < head; i++)
            data[i] = st.data[i];
    }

    T get() const {
        if (head < 1)
            return 0;
        return data[head - 1];
    }

    T pop() {
        if (head < 1)
            return 0;
        head--;
        return data[head];
    }

    void push(T element) {
        if (head >= size)
            return;
        data[head] = element;
        head++;
    }

    bool isFull() const {
        return head == size;
    }

    bool isEmpty() const {
        return head == 0;
    }

    ~MyStack() {
        delete[] data;
    }
};

#endif  // INCLUDE_MYSTACK_H_

