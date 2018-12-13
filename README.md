# cosR

This simple package contains a C++ function for computing the cosine similarity between two non-zero vectors of equal length. 

## Installation

```{r}
devtools::install_github("carter-allen/cosR")
```

## Usage

```{r}
x <- rnorm(100)
y <- rnorm(100)
cos_sim(x,y)
```
