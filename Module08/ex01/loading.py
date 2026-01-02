import importlib
import os


def display_environment():
    """Display the current environment details"""
    env = os.environ.get("VIRTUAL_ENV")
    if env is not None:
        if "poetry" in env:
            print("ENVIRONMENT: Poetry")
        else:
            print("ENVIRONMENT: Pip/venv")
    else:
        print("ENVIRONMENT: Global")


def get_module(name: str):
    """Import and return the module"""
    try:
        module = importlib.import_module(name)
        return module
    except ModuleNotFoundError:
        return None
    except ValueError as e:
        print(f"ValueError: {e}")
    except ImportError as e:
        print(f"ImportError: {e}")
    except Exception as e:
        print(f"Error: {e}")


def check_dependencies_and_run():
    """Check pandas, request and matplotlib lib module is
       installed in the python environment or not"""
    print("Checking dependencies:")
    pandas = get_module("pandas")
    pandas_status = 0
    requests = get_module("requests")
    requests_status = 0
    matplotlib = get_module("matplotlib")
    matplotlib_status = 0
    if pandas is not None:
        print(f"[OK] pandas ({pandas.__version__}) - " +
              "Data manipulation ready")
        pandas_status = 1
    else:
        print("Error: pandas module is not found")
    if requests is not None:
        print(f"[OK] requests ({requests.__version__}) - " +
              "Network access ready")
        requests_status = 1
    else:
        print("Error: requests module is not found")
    if matplotlib is not None:
        print(f"[OK] matplotlib ({matplotlib.__version__}) - " +
              "Visualization ready")
        matplotlib_status = 1
    else:
        print("Error: matplotlib module is not found")

    if (pandas_status and requests_status and matplotlib_status):
        print()
        run_analysis(pandas, requests, matplotlib)
    else:
        print("run: pip install -r requirements.txt or poetry install")


def run_analysis(pd, requests, plt):
    """Run the analysis using the pandas, requests and matplotlib
       modules"""
    try:
        mu, sigma = 0, 0.1
        np = get_module("numpy")
        simulated_data = np.random.normal(mu, sigma, 1000)
        pd = get_module("pandas")
        pd_data = pd.DataFrame(simulated_data, columns=["value"])
        print("Analyzing Matrix data...")
        pd_data.std()
    except Exception as e:
        print(f"Error: {e}")

    try:
        requests = get_module("requests")
        response = requests.get("https://google.com")
        if response.status_code == 200:
            print("Processing 1000 data points...")
    except Exception as e:
        print(f"Error: {e}")

    try:
        print("Generating visualization...")
        plt = get_module("matplotlib.pyplot")
        plt.hist(pd_data, bins=50)
        plt.savefig("matrix_analysis.png")
        print()
        print("Analysis complete!\n"
              "Results saved to: matrix_analysis.png")
    except Exception as e:
        print(f"Error: {e}")


if __name__ == "__main__":
    print("LOADING STATUS: Loading programs...")
    display_environment()
    print()
    check_dependencies_and_run()
