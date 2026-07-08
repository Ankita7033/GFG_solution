class myQueue {
    vector<int> q;
    int front, rear, cnt, size;

public:
    myQueue(int n) {
        q.resize(n);
        size = n;
        front = 0;
        rear = 0;
        cnt = 0;
    }

    bool isEmpty() {
        return cnt == 0;
    }

    bool isFull() {
        return cnt == size;
    }

    void enqueue(int x) {
        if (isFull()) return;

        q[rear] = x;
        rear = (rear + 1) % size;
        cnt++;
    }

    void dequeue() {
        if (isEmpty()) return;

        front = (front + 1) % size;
        cnt--;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return q[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return q[(rear - 1 + size) % size];
    }
};