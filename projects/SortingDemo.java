import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Random;
import java.util.stream.Collectors;

public class SortingDemo {
    public static void main(String[] args) {
        int size = 1000000;
        int[] arr = new int[size];
        Random random = new Random();

        for (int i = 0; i < size; i++) {
            arr[i] = random.nextInt();
        }

        // Arrays.sort()
        int[] arrCopy = Arrays.copyOf(arr, size);
        long startTime = System.currentTimeMillis();
        Arrays.sort(arrCopy);
        long endTime = System.currentTimeMillis();
        System.out.println("Arrays.sort() time: " + (endTime - startTime) + " ms");

        // Collections.sort()
        List<Integer> list = Arrays.stream(arr).boxed().collect(Collectors.toList());
        startTime = System.currentTimeMillis();
        Collections.sort(list);
        endTime = System.currentTimeMillis();
        System.out.println("Collections.sort() time: " + (endTime - startTime) + " ms");

        // List.sort()
        list = Arrays.stream(arr).boxed().collect(Collectors.toList());
        startTime = System.currentTimeMillis();
        list.sort(null);
        endTime = System.currentTimeMillis();
        System.out.println("List.sort() time: " + (endTime - startTime) + " ms");

        // Stream.sorted()
        list = Arrays.stream(arr).boxed().collect(Collectors.toList());
        startTime = System.currentTimeMillis();
        List<Integer> sortedList = list.stream().sorted().collect(Collectors.toList());
        endTime = System.currentTimeMillis();
        System.out.println("Stream.sorted() time: " + (endTime - startTime) + " ms");
    }
}

