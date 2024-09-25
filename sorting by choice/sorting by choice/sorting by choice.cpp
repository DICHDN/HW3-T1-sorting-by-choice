/*
Задание 1
Сортировка выбором
- Реализуйте алгоритм сортировки выбором.
- Сортировка выбором состоит в том, что в неупорядоченном списке находится наименьший элемент.
- Выбранный в исходном списке минимальный элемент записывается на i-е место исходного списка (i=1,2,…,п), а элемент с i-го места — на место выбранного.
    При этом очевидно, что уже упорядоченные элементы, а они будут расположены, начиная с первого места,
    исключаются из дальнейшей сортировки, поэтому длина списка, участвующего в каждом последующем просмотре, должна быть на один элемент меньше предыдущего.
- Поиск минимального элемента реализуйте в виде асинхронной задачи.
- Результат должен возвращаться в основной поток через связку std::promise-std::future.
*/

#include <iostream>
#include<vector>
#include<random>
#include <thread>
#include <future>





// Асинхронная функция для поиска минимального элемента в массиве
std::future<int> findMinAsync(const std::vector<int>&arr, int start, int end) 
{
    return std::async(std::launch::async, [arr, start, end]() 
        {
        int minIdx = start;
        for (int i = start + 1; i < end; ++i) 
        {
            if (arr[i] < arr[minIdx])
            {
                minIdx = i;
            }
        }
        return minIdx;
        });
}

// Основная функция сортировки выбором
void selectionSort(std::vector<int>& arr)
{
    for (int i = 0; i < arr.size() - 1; ++i) 
    {
        std::future<int> minIdxFuture = findMinAsync(arr, i, arr.size());
        int minIdx = minIdxFuture.get();

        // Меняем местами минимальный элемент и элемент на i-ом месте
        std::swap(arr[i], arr[minIdx]);
    }
}

int main() {
    std::vector<int> arr = { 64, 25, 12, 22, 11 };
    selectionSort(arr);

    for (int num : arr) 
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}