#include <iostream>
#include <vector>
using namespace std;
class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else break;
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (index < size) {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size && heap[left] > heap[largest]) {
                largest = left;
            }
            if (right < size && heap[right] > heap[largest]) {
                largest = right;
            }

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else break;
        }
    }

    void checkHeapProperty() {
        bool valid = true;
        for (int i = 0; i < heap.size(); ++i) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < heap.size() && heap[i] < heap[left]) {
                cout << "Heap property violated at index " << i << " (left child)\n";
                valid = false;
                break;
            }
            if (right < heap.size() && heap[i] < heap[right]) {
                cout << "Heap property violated at index " << i << " (right child)\n";
                valid = false;
                break;
            }
        }
        if (valid)
            cout << "Heap property maintained.\n" << endl;
    }
public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
        cout << "Inserted " << val << ": ";
        printHeap();
        checkHeapProperty();
    }
    void deleteMax() {
        if (heap.empty()) {
            cout << "Heap is empty.\n";
            return;
        }
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        cout << "Deleted max (" << maxVal << "): ";
        printHeap();
        checkHeapProperty();
    }
    void printHeap() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};
int main() {
    MaxHeap heap;
    vector<int> data = {50, 10, 30, 20, 60, 70};
    cout << "=== Inserting Elements ===" << endl;
    for (int val : data) {
        heap.insert(val);
    }
    cout << "=== Deleting Max Twice ===" << endl;
    heap.deleteMax();
    heap.deleteMax();
    return 0;
}
