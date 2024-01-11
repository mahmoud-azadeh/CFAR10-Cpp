import numpy as np
import matplotlib.pylab as plt

def to_uint32(data):
    # data = data.astype(np.uint32)
    return data[0] + (data[1] << 8) + (data[2] << 16) + (data[3] << 24)
    

def read_binary(filename, dtype = np.uint8):
    read_data = np.fromfile(filename,  dtype=dtype);
    
    dim1 = to_uint32(read_data[0:4])
    dim2 = to_uint32(read_data[4:8])
   
    data = np.reshape(read_data[8::], (dim1, dim2))
    return data;

def plot_images(images, labels): # reference: https://cs231n.github.io/classification/
    plt.ion()
    classes     = ['plane', 'car', 'bird', 'cat', 'deer', 'dog', 'frog', 'horse', 'ship', 'truck']
    num_classes = len(classes)
    samples_per_class = 7
    for y, cls in enumerate(classes):
        idxs = np.flatnonzero(labels == y)
        idxs =  np.random.choice(idxs, samples_per_class, replace=False) if len(idxs) > samples_per_class else idxs;
        for i, idx in enumerate(idxs):
            plt_idx = i * num_classes + y + 1
            plt.subplot(samples_per_class, num_classes, plt_idx)
            plt.imshow(images[idx].astype('uint8'))
            plt.axis('off')
            if i == 0:
                plt.title(cls)
    plt.show()

if __name__ == "__main__":    
    images = read_binary('./X_train.bin');
    labels = read_binary('./y_train.bin');

    # images = read_binary('./X_val.bin');
    # labels = read_binary('./y_val.bin');

    # images = read_binary('./X_test.bin');
    # labels = read_binary('./y_test.bin');

    images = images.reshape(-1, 3, 32, 32).transpose(0, 2, 3, 1)

    plot_images(images, labels)
