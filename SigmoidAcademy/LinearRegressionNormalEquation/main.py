import numpy as np
from sklearn.datasets import make_regression
from sklearn.linear_model import LinearRegression

def linear_regression(X, y):
    if len(np.shape(X)) != 2:
        print("Please supply a 2D matrix for X!")
        return []

    if len(np.shape(y)) != 1:
        print("Please supply a 1D matrix for y!")
        return []

    if np.shape(X)[0] != np.shape(y)[0]:
        print("Dimensions of y did not match dimensions of X!")
        return []

    X_intercept = np.c_[np.ones((X.shape[0], 1)), X]
    X_t = np.transpose(X_intercept)
    X_t_X = X_t @ X_intercept
    try:
        X_t_X_inv = np.linalg.inv(X_t_X) 
        X_t_X_inv_X_t = X_t_X_inv @ X_t

        return X_t_X_inv_X_t @ y
    except np.linalg.LinAlgError:
        print("Could't compute the inverse matrix of X! Please ensure it is a 2D matrix.")
        return []

def linear_regression_with_model(X, y):
    linear_regression = LinearRegression()
    linear_regression = linear_regression.fit(X, y)

    return [linear_regression.intercept_, linear_regression.coef_[1:]]

def main():
    X, y = make_regression(
        n_samples=100,
        n_features=1,
        n_informative=1,
        noise=10,
        random_state=10,
        bias=1.0
    )
    print("Normal Calculation: " + str(linear_regression(X, y)))
    print("Model Calculation: " + str(linear_regression_with_model(X, y)))

if __name__ == "__main__":
    main()