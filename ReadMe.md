### Задание 1#### Сортировка выбором
* Реализуйте алгоритм сортировки выбором.
<br/>Сортировка выбором состоит в том, что в неупорядоченном списке находится наименьший элемент.
 Выбранный в исходном списке минимальный элемент записывается на i-е место исходного списка (i=1,2,…,п), а элемент с i-го места — на место выбранного. При этом очевидно, что уже упорядоченные элементы, а они будут расположены, начиная с первого места, исключаются из дальнейшей сортировки, поэтому длина списка, участвующего в каждом последующем просмотре, должна быть на один элемент меньше предыдущего.
 <br/>* Поиск минимального элемента реализуйте в виде асинхронной задачи.
 <br/>* Результат должен возвращаться в основной поток через связку std::promise-std::future.
