
import torchvision.datasets as datasets

mnist_trainset = datasets.MNIST(root='./', train=True, download=True, transform=None)