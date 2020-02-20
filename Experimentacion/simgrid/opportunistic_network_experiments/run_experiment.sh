run_simulation() {
	`./$1 $2 $3`
}

EXPERIMENT_NAME=$1
REDUNDANCY=${2:-""}
THRESHOLD=${3:-""}

make $EXPERIMENT_NAME
cd $EXPERIMENT_NAME

if [ -z "$REDUNDANCY" ]
then
	echo "running $EXPERIMENT_NAME with all possible combinations of redundancy and threshold"

	run_simulation "$EXPERIMENT_NAME" "no_redundancy" "no_threshold"
	run_simulation "$EXPERIMENT_NAME" "no_redundancy" "threshold"
	run_simulation "$EXPERIMENT_NAME" "redundancy" "no_threshold"
	run_simulation "$EXPERIMENT_NAME" "redundancy" "threshold"
else
	echo "running $EXPERIMENT_NAME with redundancy: $REDUNDANCY and threshold: $THRESHOLD"
	run_simulation "$EXPERIMENT_NAME" "$REDUNDANCY" "$THRESHOLD"
fi

cd ..