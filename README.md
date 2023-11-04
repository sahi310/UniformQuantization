# UniformQuantization

**A program to generate a color quantized image for an input image using the uniform quantization**

bhava2.c is the main file
In this file we will implement the actual logic. We will take an array of 265 size and then based a qunatization value we will divide the array into that many equal halves. Post division we will check for the pixel value in the array. For that array we will calculate the mean. Like this we will repeat the loop for all the pixel. At lst we will form the result.
Below are the results for 2,4,8,16 - image quantization.

original image : 
<img width="103" alt="image" src="https://github.com/sahi310/UniformQuantization/assets/52164692/f958e7be-bca3-4b39-ac81-07c6ffc6ddff">
2- color output :
<img width="107" alt="image" src="https://github.com/sahi310/UniformQuantization/assets/52164692/3b981cde-88cd-49ff-a56d-66b6bd6cd7fc">
4- color output :
<img width="106" alt="image" src="https://github.com/sahi310/UniformQuantization/assets/52164692/5488ff61-a0d8-4585-98da-d9a7b76b6bc4">
8- color output :
<img width="104" alt="image" src="https://github.com/sahi310/UniformQuantization/assets/52164692/5a09f5f0-a957-4779-8de8-a49bb16e6b95">
16 - color output :
<img width="104" alt="image" src="https://github.com/sahi310/UniformQuantization/assets/52164692/994f42f3-a515-4950-a087-a510aa497d58">

bhava2_old.c and test1.c - In this files you can find the code which satisfies our requirment. But different logic are used.
bhava2_old has more time complexity than compared to test2.c







