


void push_heap(vector<int>& heap, int newValue) {
    heap.push_back(newValue);
    int n = heap.size();
    int i = n-1;
    while (i > 0 && heap[i] > heap[(i-1)/2]) {
        swap(heap[i], heap[(i-1)/2]);
        i = (i-1) /2;
    }
}


void pop_heap(vector<int>& heap) {
    heap[0] = heap.back();
    heap.pop_back();
    int here = 0;
    while(true) {
        int left = 2*here + 1;
        int right = 2*here + 2;

        if (left >= heap.size()) break;

        int next =  here;
        if (heap[next] < heap[left]) {
            next = left
        }

        if (right < heap.size() && heap[next] < heap[right])
            next = right;

        if (next == here) break;
        swap(heap[here], heap[next]);
        here = next;
    }
}